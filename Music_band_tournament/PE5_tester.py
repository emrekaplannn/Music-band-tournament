import glob
import subprocess
import os

def compare_files(file1, file2):
    with open(file1, 'r') as f1, open(file2, 'r') as f2:
        lines1 = f1.readlines()
        lines2 = f2.readlines()

    max_lines = max(len(lines1), len(lines2))
    identical = False

    for line_num in range(max_lines):
        if line_num < len(lines1) and line_num < len(lines2):
            if lines1[line_num] != lines2[line_num]:
                print(f"Line {line_num + 1}:")
                print(f"Expected: {lines1[line_num].strip()}")
                print(f"Returned: {lines2[line_num].strip()}")
                identical = True
        elif line_num < len(lines1):
            print(f"Line {line_num + 1}:")
            print(f"Expected:: {lines1[line_num].strip()}")
            print(f"Returned: Line number exceeded")
            identical = True
        elif line_num < len(lines2):
            print(f"Line {line_num + 1}:")
            print(f"Expected: Line number exceeded")
            print(f"Returned: {lines2[line_num].strip()}")
            identical = True
    return not identical


output_folder = "outputs"
if not os.path.exists(output_folder):
    os.makedirs(output_folder)

sourcefiles = " ".join(["tournament_round.cpp", "tournament.cpp", "music_band.h", "jazz.cpp", "rock.cpp", "metal.cpp", "kpop.cpp"])
testcases = glob.glob("testcases/*.cpp")
outputfiles = glob.glob("testcases/*.out")
cpp = "c++ -I./. -Wall -Wpedantic -Werror -std=c++11"

passed = 0
total = len(testcases)

for testcase in testcases:
    name = testcase.replace("testcases", "outputs")
    output_exe = name.replace(".cpp", ".exe")
    output_file = name.replace(".cpp", ".out")
    expected_output_file = testcase.replace(".cpp", ".out")
    command = cpp + " -o " + output_exe + " " + testcase + " " + sourcefiles + " && " + output_exe + " > " + output_file
    
    try:
        subprocess.check_output(command, shell=True)
        
        print("Compilation successful for:", testcase)

        if compare_files(expected_output_file, output_file):
            print("Passed")
            passed += 1
        else:
            print("Failed")

    except subprocess.CalledProcessError as e:
        print("Compilation failed for:", testcase)
        print("Error:", e)
    print("\n")
        
print("Passed:", passed, "/", total)
print("Score:", passed * 100 / total)