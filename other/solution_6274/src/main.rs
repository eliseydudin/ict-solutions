use std::collections::HashSet;

type Results = HashSet<Vec<i32>>;

pub fn concatenate(mut arr: Vec<i32>, v: i32) -> Vec<i32> {
    arr.push(v);
    return arr;
}

pub fn solve_with_claimed(curr: i32, results: &mut Results, claimed: &Vec<i32>) {
    if curr == 42 {
        results.insert(claimed.clone());
    }
    if claimed.len() > 10 {
        return;
    }
    if curr < 49 && !claimed.contains(&(curr + 1)) {
        solve_with_claimed(curr + 1, results, &concatenate(claimed.clone(), curr + 1));
    }
    if curr > 40 && !claimed.contains(&(curr - 1)) {
        solve_with_claimed(curr - 1, results, &concatenate(claimed.clone(), curr - 1));
    }
    if curr <= 46 && !claimed.contains(&(curr + 3)) {
        solve_with_claimed(curr + 3, results, &concatenate(claimed.clone(), curr + 3));
    }
    if curr >= 43 && !claimed.contains(&(curr - 3)) {
        solve_with_claimed(curr - 3, results, &concatenate(claimed.clone(), curr - 3));
    }
}

pub fn solve(results: &mut Results) {
    let curr = 42;
    let claimed = Vec::new();

    solve_with_claimed(curr, results, &claimed);
}

fn main() {
    let mut results: Results = HashSet::new();
    solve(&mut results);

    println!("{}", results.len());

    for arr in results {
        println!("{:?}", arr)
    }
}
