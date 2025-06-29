import os  

def prepend_prefix_to_filenames(folder_path, prefix):  
    # 获取文件夹中的所有文件  
    sum = 0
    for filename in os.listdir(folder_path):  
        # # 构建旧文件的完整路径  
        # old_file_path = os.path.join(folder_path, filename)  
        
        # # 确保它是一个文件  
        # if os.path.isfile(old_file_path):  
        #     # 构建新的文件名  
        #     new_filename = f"{prefix}{filename}"  
        #     new_file_path = os.path.join(folder_path, new_filename)  

        #     # 重命名文件  
        #     os.rename(old_file_path, new_file_path)  
        #     print(f'Renamed: "{filename}" to "{new_filename}"')  
        sum = sum + 1
    print(sum)

if __name__ == "__main__":  
    # 设置文件夹路径和前缀  
    folder_path = "D:\\study\\algorithm\\leetcode\\practice - 副本"  # 例如 "C:\\path\\to\\your\\folder"  
    prefix = "leetcode"  
    
    prepend_prefix_to_filenames(folder_path, prefix)  