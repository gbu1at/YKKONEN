import os
import sys



good = "good"
source = "../source"
gen = "gen"
n = 10

os.system(f"g++ {good}.cpp -o {good}.exe")
os.system(f"g++ {source}.cpp -o {source}.exe")
os.system(f"g++ {gen}.cpp -o {gen}.exe")


for i in range(int(n)):
	os.system(f"./{gen}.exe {i + 1} > input.txt")
	os.system(f"./{good}.exe < input.txt > good.txt")
	os.system(f"./{source}.exe < input.txt > bad.txt")
	g = open(f"good.txt").read()
	b = open(f"bad.txt").read()
	if g == b:
		print(f"Test {i + 1}: [+]")
	else:
		print(f"Test {i + 1}: [-]")
		break