# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/04 12:01:58 by jfleury           #+#    #+#              #
#    Updated: 2019/07/15 18:04:59 by jfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/python3.7
# -*-coding:Utf-8 -*

import os
import glob
import sys

def init_project():
	os.system("make")
	os.system("clear")
	print()

def search_files():
	os.chdir("test_tool/champion")
	list_files = glob.glob("*.s")
	return list_files

def cal_file_cor(file):
	str = file
	str = str.split('.')
	str[0] = str[0] + ".cor"
	return (str[0])

def export_error(file, export_error):
	str = file.split('.')
	os.system("rm -f ../../error_" + str[0])
	error_file = open("error_" + str[0], 'x')
	hex_zaz = os.popen("hexdump test_zaz.cor", 'r').read()
	hex_us = os.popen("hexdump test_us.cor", 'r').read()
	error_file.write(export_error + "\n\n")
	error_file.write("\tzaz hexdump :\n\n")
	error_file.write(hex_zaz + "\n\n")
	error_file.write("\tasm hexdump :\n\n")
	error_file.write(hex_us)
	os.system("mv error_" + str[0] + " ../../")

def	check_cor(file):
	name_cor = cal_file_cor(file)

	#Zaz compile
	os.system("../asm_zaz " + file + " > /dev/null")
	try:
 		with open(name_cor): pass
	except IOError:
		print(file + "\t\t\t\x1B[31mzaz not compile\x1B[0m")
		return
	os.system("mv " + name_cor + " test_zaz.cor")

	#Asm Compile
	os.system("../../asm " + file + " > /dev/null")
	try:
 		with open(name_cor): pass
	except IOError:
		print(file + "\t\t\t\x1B[31masm not compile\x1B[0m")
		return
	os.system("mv " + name_cor + " test_us.cor")

	#Diff
	exit_diff = os.popen("cmp test_zaz.cor test_us.cor", 'r').read()
	#Check Diff
	if not exit_diff:
		print(file + "\t\t\t\x1B[32mok\x1B[0m")
	else:
		print(file + "\t\t\t\x1B[31mko\x1B[0m")
		export_error(file, exit_diff)
	os.system("rm test_us.cor test_zaz.cor")

if __name__ == "__main__":
	init_project()
	list_files = search_files()
	print("\x1B[01m\x1B[04mFiles:\t\t\tresult:\x1B[0m")
	i = 0
	while i < len(list_files):
		check_cor(list_files[i])
		i = i + 1
