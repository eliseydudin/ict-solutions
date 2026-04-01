#!/usr/bin/env python3

import argparse
import subprocess
from os import listdir, path

# short forms of the possible directories
DIRECTORY_SHORT = {
    "acmp": "acmp",
    "cf": "codeforces",
    "inf": "informatics",
    "leet": "leetcode",
    "mosh25": "mosh_ict_2025",
    "muni2": "municip2",
    "timus": "timus",
    "tbank": "tbank_otbor_2025",
}


def run_cmd(*cmd: str, shell=True) -> int:
    return subprocess.call(cmd, shell=shell)


# get the possible runners for a task
def get_possible_runners(filenames: list[str]) -> set[str]:
    runners: set[str] = set()

    for filename in filenames:
        _base, ext = path.splitext(filename)

        match ext:
            case "":
                runners.add("go")
            case ".py":
                runners.add("python")
            case ".cpp" | ".c":
                runners.add("c++")
            case _:
                print(f"warning: unknown extension on file {filename}")

    return runners


def run(dir: str, task: str, runner: str) -> int:
    match runner:
        case "go":
            return run_cmd("go", "run", f"./{dir}/{task}/main.go", shell=False)
        case "python":
            return run_cmd("python3", f"./{dir}/{task}.py", shell=False)
        case "c++":
            if not path.exists("builddir"):
                run_cmd("meson", "setup", "builddir", shell=False)
            run_cmd(
                "meson", "compile", "-C", "builddir", shell=False
            )  # compile everything
            return run_cmd(f"./builddir/{dir}/{task}")
        case _:
            pass

    return 0


# the main function, returns a number that should be the exit code of the program
def main(
    dir: str,
    task: str,
) -> int:
    if dir not in DIRECTORY_SHORT:
        print("error: unknown directory")
        return 1

    actual_dir = DIRECTORY_SHORT[dir]
    possible_tasks = filter(
        lambda x: path.basename(x).split(".")[0] == task,
        listdir(actual_dir),
    )

    runners = get_possible_runners(list(possible_tasks))

    if len(runners) == 0:
        print("error: no runners found")
        return 1
    else:
        print("found solutions in the following languages:", *runners)

        if len(runners) == 1:
            runner = runners.pop()
        else:
            runner = input("which one to run: ")
            if runner not in runners:
                print("error: invalid runner")
                return 1

    return run(actual_dir, task, runner)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        prog="run", description="run a solution for a task in this repository"
    )
    parser.add_argument(
        "dir",
        help="The directory that contains the task",
        choices=DIRECTORY_SHORT.keys(),
    )
    parser.add_argument("task", help="the task to run")
    args = parser.parse_args()

    result = main(args.dir, args.task)
    print(
        f"the program ended with the code {hex(result)}, {'success' if result == 0 else 'failure'}"
    )

    exit(result)
