from sys import stdin
# while True:
#     try:
#         nums = list(map(int, input().split()))
#     except EOFError:
#         break


nums = list()
for line in stdin:
    print(line.strip());
    if not line:
        break
# print(*nums)
