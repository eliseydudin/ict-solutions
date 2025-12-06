# 15/49 points
from itertools import permutations

def main():
	n, k = map(int, input().split())
	min_apples = 2147483647
	
	for ranks in permutations(range(1, n + 1)):
		apples = k
		apples_of_all = [0] * n
		
		i = 0
		
		while True:
			rank = ranks[i]
			
			if apples < rank:
				apples_of_all[i] += apples
				break
			elif apples > rank:
				apples_of_all[i] += rank
				apples -= rank
			else:
				break
				
			i = (i + 1) % len(ranks)
		
		min_apples = min(min_apples, min(apples_of_all))
		
	print(min_apples)
		
if __name__ == "__main__":
	main()
