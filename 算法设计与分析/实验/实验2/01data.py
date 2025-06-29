import random

def generate_knapsack_data(num_items, weight_range, value_range):
    items = []
    for _ in range(num_items):
        weight = random.randint(*weight_range)
        value = random.randint(*value_range)
        items.append((weight, value))
    return items

def write_data_to_file(items, num_items, knapsack_capacity, filename):
    with open(filename, 'w') as file:
        file.write(f"{num_items} {knapsack_capacity}\n")
        for i, (weight, value) in enumerate(items):
            file.write(f"{weight} {value}\n")

def main():
    num_items = 10000  # 物品数量
    weight_range = (50, 200)  # 重量范围
    value_range = (1, 100)  # 价值范围
    knapsack_capacity = 5000  # 随机生成背包容量

    knapsack_data = generate_knapsack_data(num_items, weight_range, value_range)
    # 将数据写入文件
    write_data_to_file(knapsack_data, num_items, knapsack_capacity, 'testData/mid_1.txt')

if __name__ == "__main__":
    main()
