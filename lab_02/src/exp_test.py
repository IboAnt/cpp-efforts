#!/usr/bin/env python3
import time

def calculate(x):
	return x*x - x*x + x*4 - x*5 + x + x

def main():
	n = 1.0
	while True:
		user_input = input("Enter num of iterations: ")

		try:
			n = int(user_input)
		except ValueError:
			print("Invalid input. Please enter a number")
			break

		if n <= 0:
			break

		start = time.time()
		for _ in range(n):
			calculate(n)
		end = time.time()

		seconds = end - start
		print(f"Time: {seconds:.6f} seconds")

	print("Error. Try Again")
main()
