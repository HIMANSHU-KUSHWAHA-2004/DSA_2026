import os
from datetime import datetime

# Main Folder Path
MAIN_PATH = r"C:\Users\hk565\OneDrive\Desktop\DSA"

# Check if main folder exists
if not os.path.exists(MAIN_PATH):
    print("❌ Main folder not found.")
    exit()


# Recursive Folder Explorer
def explore_folder(current_path):

    while True:

        print(f"\n📂 CURRENT FOLDER: {os.path.basename(current_path)}")

        items = os.listdir(current_path)

        folders = []
        files = []

        # Separate folders and files
        for item in items:

            full_path = os.path.join(current_path, item)

            if os.path.isdir(full_path):
                folders.append(item)

            else:
                files.append(item)

        # Show folders
        print("\n📁 FOLDERS:\n")

        if len(folders) == 0:
            print("No folders found.")

        else:
            for index, folder in enumerate(folders, start=1):
                print(f"{index}. 📁 {folder}")

        # Count .exe files
        exe_count = 0

        for file in files:
            if file.endswith(".exe"):
                exe_count += 1

        print(f"\n.exe Files Found: {exe_count}")

        print("\nOPTIONS:")
        print("👉 Enter folder number to OPEN folder")
        print("👉 Enter D to DELETE all .exe files")
        print("👉 Enter B to go BACK")
        print("👉 Enter Q to QUIT")

        choice = input("\nYour Choice: ").strip()

        # Quit
        if choice.lower() == "q":
            print("\n👋 Exiting Cleaner Tool...")
            exit()

        # Go Back
        elif choice.lower() == "b":

            # Prevent going above main folder
            if os.path.abspath(current_path) == os.path.abspath(MAIN_PATH):
                print("⚠️ Already in main folder.")

            else:
                return

        # Delete .exe files only
        elif choice.lower() == "d":

            deleted_count = 0

            for file in files:

                if file.endswith(".exe"):

                    file_path = os.path.join(current_path, file)

                    try:
                        file_size = os.path.getsize(file_path)

                        os.remove(file_path)

                        deleted_count += 1

                        print(f"🗑️ Deleted: {file} "
                              f"({round(file_size / 1024, 2)} KB)")

                    except Exception as e:
                        print(f"⚠️ Error deleting {file}: {e}")

            print("\n" + "=" * 60)
            print("✨ CLEANING COMPLETE ✨")
            print("=" * 60)

            print(f"🗑️ Total .exe Deleted: {deleted_count}")

            current_time = datetime.now().strftime(
                "%d-%m-%Y %H:%M:%S"
            )

            print(f"⏰ Time: {current_time}")

        # Open Folder
        else:

            try:

                folder_index = int(choice)

                if folder_index < 1 or folder_index > len(folders):
                    print("❌ Invalid Folder Number.")

                else:

                    selected_folder = folders[folder_index - 1]

                    next_path = os.path.join(
                        current_path,
                        selected_folder
                    )

                    # Recursive call
                    explore_folder(next_path)

            except ValueError:
                print("❌ Invalid Input.")


# Start Program
print("\n" + "=" * 60)
print("🔥 ADVANCED DSA CLEANER TOOL 🔥".center(60))
print("=" * 60)

explore_folder(MAIN_PATH)