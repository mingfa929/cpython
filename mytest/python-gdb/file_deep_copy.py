import os
import shutil

def copy_directory(src, dst):
    for item in os.listdir(src):
        src_path = os.path.join(src, item)
        dst_path = os.path.join(dst, item)
        if os.path.isdir(src_path):
            if not os.path.exists(dst_path):
                os.makedirs(dst_path)
            copy_directory(src_path, dst_path)
        else:
            #if not os.path.exists(dst_path) or os.path.getmtime(src_path) > os.path.getmtime(dst_path):
                shutil.copy2(src_path, dst_path)

source_directory = './sorce_dir'
target_directory = './target_dir'
copy_directory(source_directory, target_directory)
