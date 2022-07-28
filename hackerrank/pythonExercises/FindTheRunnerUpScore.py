input_list = list(arr)
input_list.sort()
max_value = max(input_list)
runner_up = input_list[input_list.index(max_value) - 1]
print(runner_up)
