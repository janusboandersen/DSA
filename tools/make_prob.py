#!/usr/bin/env python3

"""
Make scaffolding for the solution to a LeetCode problem

Usage example:
  Command: tools/make_prob.py 876 middle_of_linked_list
  Effect: Will create scaffolding for LeetCode problem 876 named 'Middle of linked list'.

Files are created using the templates in tools/templates, which are populated using this current script. The following filesystem effects occur:

1) Three new files will be created:
  + src/include/876/middle_of_linked_list.hpp
  + src/876_middle_of_linked_list.cpp
  + test/testcases/876/test_middle_of_linked_list.cpp

2) Prompts are issued to make the required manual modifications (copy-paste) in CMake-files:
  src/CMakeLists.txt:
  -> LIB_HEADERS: + include/876/middle_of_linked_list.hpp
  -> LIB_SOURCES: + 876_middle_of_linked_list.cpp

  test/CMakeLists.txt:
  -> TEST_FILES: + ${TEST_DIR}/876/test_middle_of_linked_list.cpp

Janus Bo Andersen, June 2023.

"""

import sys
import os
from datetime import date
from jinja2 import Environment, FileSystemLoader, select_autoescape

env = Environment(
    loader=FileSystemLoader(os.path.join("tools", "templates")),
    autoescape=select_autoescape()
)

HEADER_EXT = ".hpp"
SOURCE_EXT = ".cpp"

def get_problem_num() -> str:
    return sys.argv[1]

def get_problem_name() -> str:
    return sys.argv[2]

def make_problem_name_cleartext(prob_name: str) -> str:
    return prob_name.replace("_", " ").capitalize()

# 876/middle_of_linked_list.hpp   ... #include <876/middle_of_linked_list.hpp>
def make_include_header(prob_num: str, prob_name: str) -> str:
    return prob_num + "/" + prob_name + HEADER_EXT

# src/include/876
def make_header_rel_path(prob_num: str, prob_name: str) -> str:
    return os.path.join("src", "include", prob_num)

# middle_of_linked_list.hpp
def make_header_filename(prob_num: str, prob_name: str) -> str:
    return prob_name + HEADER_EXT

# src/include/876/middle_of_linked_list.hpp
def make_header_rel_path_with_filename(prob_num: str, prob_name: str) -> str:
    return os.path.join(
        make_header_rel_path(prob_num, prob_name),
        make_header_filename(prob_num, prob_name)
    )

# src
def make_source_rel_path(prob_num: str, prob_name: str) -> str:
    return os.path.join("src")

# 876_middle_of_linked_list.cpp
def make_source_filename(prob_num: str, prob_name: str) -> str:
    return os.path.join(prob_num + "_" + prob_name + SOURCE_EXT)

# src/876_middle_of_linked_list.cpp
def make_source_rel_path_with_filename(prob_num: str, prob_name: str) -> str:
    return os.path.join(
        make_source_rel_path(prob_num, prob_name),
        make_source_filename(prob_num, prob_name)
    )

# test/testcases/876
def make_test_rel_path(prob_num: str, prob_name: str) -> str:
    return os.path.join("test", "testcases", prob_num)

# test_middle_of_linked_list.cpp
def make_test_filename(prob_num: str, prob_name: str) -> str:
    return os.path.join("test_" + prob_name + SOURCE_EXT)

# test/testcases/876/test_middle_of_linked_list.cpp
def make_test_rel_path_with_filename(prob_num: str, prob_name: str) -> str:
    return os.path.join(
        make_test_rel_path(prob_num, prob_name),
        make_test_filename(prob_num, prob_name)
    )

# Creates full path and writes to file, but doesn't overwrite existing files
def write_to_file(basepath: str, rel_path: str, filename: str, textdata: str) -> int:
    path = os.path.join(basepath, rel_path)
    path_and_file = os.path.join(path, filename)

    if not os.path.exists(path):
        print("Making path: " + path)
        os.makedirs(path)

    if not os.path.isfile(path_and_file):
        print("Making file: " + path_and_file)
        f = open(path_and_file, "wt")
        n = f.write(textdata)
        f.close()
        return n
    else:
        print("File already exists: " + path_and_file)
        return 0


if __name__ == "__main__":
    pname = get_problem_name()
    pnum = get_problem_num()
    
    render_vars = {
        "header_file": make_header_rel_path_with_filename(pnum, pname),
        "include_header": make_include_header(pnum, pname),
        "source_file": make_source_rel_path_with_filename(pnum, pname),
        "test_file": make_test_rel_path_with_filename(pnum, pname),
        "problem_number": pnum,
        "problem_name": pname,
        "problem_name_clear_text": make_problem_name_cleartext(pname),
        "make_date": date.today().isoformat(),
        "make_year": date.today().year,
        "problem_namespace": "p" + pnum
    }

    # Build header file
    header_template = env.get_template("header.hpp.jinja2")
    write_to_file(
        os.getcwd(),
        make_header_rel_path(pnum, pname),
        make_header_filename(pnum, pname),
        header_template.render(**render_vars)
    )

    # Build source file
    source_template = env.get_template("source.cpp.jinja2")
    write_to_file(
        os.getcwd(),
        make_source_rel_path(pnum, pname),
        make_source_filename(pnum, pname),
        source_template.render(**render_vars)
    )

    # Build test file
    test_template = env.get_template("test.cpp.jinja2")
    write_to_file(
        os.getcwd(),
        make_test_rel_path(pnum, pname),
        make_test_filename(pnum, pname),
        test_template.render(**render_vars)
    )

    # Give user strings to copy to CMakeLists

    # src/CMakeLists.txt
    lib_sources = make_source_filename(pnum, pname)
    lib_headers = f"include/{pnum}/{make_header_filename(pnum, pname)}"
    print("\nManual edit required: src/CMakeLists.txt ->")
    print("LIB_SOURCES: " + lib_sources)        # 876_middle_of_linked_list.cpp
    print("LIB_HEADERS: " + lib_headers)        # include/876/middle_of_linked_list.hpp
    
    #test/CMakeLists.txt
    test_files = "${TEST_DIR}/" + f"{pnum}/{make_test_filename(pnum, pname)}"
    print("\nManual edit required: test/CMakeLists ->")
    print("TEST_FILES: " + test_files)          # ${TEST_DIR}/876/test_middle_of_linked_list.cpp
