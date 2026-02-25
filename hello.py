import os

# Use your actual Windows path
folder_path = r"C:\Users\hk565\OneDrive\Desktop\DSA"  

folder = input("Enter the folder name you wanna delete all exe and dll files from: ")
target_path = os.path.join(folder_path, folder)

if not os.path.exists(target_path):
    print(f"❌ Folder not found: {target_path}")
else:
    for filename in os.listdir(target_path):
        file_path = os.path.join(target_path, filename)
        if os.path.isfile(file_path) and not (filename.endswith(".cpp") or filename.endswith(".py")):
            try:
                os.remove(file_path)
                print(f"✅ Deleted: {file_path}")
            except Exception as e:
                print(f"⚠️ Error deleting {file_path}: {e}")

    print("✨ Deletion complete.")
