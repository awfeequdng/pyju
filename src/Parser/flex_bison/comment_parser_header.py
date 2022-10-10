

find_str = "#include \"parser.h\""
replace_str = "//#include \"parser.h\""
with open("parser.cpp", "r+") as fr:
    data = fr.read()
    data = data.replace(find_str, replace_str)

with open("parser.cpp", "w", encoding='UTF-8') as fw:
    fw.write(data)


