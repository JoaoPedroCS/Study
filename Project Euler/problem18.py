import time
start_time = time.time()
data = """
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
"""
row0 = []
def parse_triangle() -> list[list[int]]:
    return [[int(word) for word in line.split()] for line in data.strip().split("\n")]

triangle = parse_triangle()
lines = len(triangle)
for i in range(lines):
    globals()[f'row{i}'] = triangle[i]

for k in range(lines-2, -1, -1):    
    for j in range(len(globals()[f'row{k}'])):
        if globals()[f'row{k+1}'][j] >= globals()[f'row{k+1}'][j+1]:
            globals()[f'row{k}'][j] += globals()[f'row{k+1}'][j]
        else:
            globals()[f'row{k}'][j] += globals()[f'row{k+1}'][j+1]

print(f"answer: {row0[0]}, in {(time.time() - start_time):.5f} seconds")
