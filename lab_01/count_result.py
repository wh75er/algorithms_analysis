read_path = "tests/test_output"
write_path = "tests/test_results"
read_path_rec = "tests/test_output_recursive"
write_path_rec = "tests/test_results_recursive"

read_file = read_path_rec
write_file = write_path_rec

f = open(read_file, 'r')
m = open(write_file, 'w')

l = 0;
d = 0;
r = 0;
for i in f:
    if (i[0][0] != '-'):
        for j in range(len(i.split())):
            if(j == 0):
                l+=float(i.split()[j])
            if(j == 1):
                d+=float(i.split()[j])
            if(j == 2):
                r+=float(i.split()[j])
    else:
        if(read_file == read_path):
            print(l/100*1000000, d/100*1000000, file=m)
        if(read_file == read_path_rec):
            print(l/100*1000000, d/100*1000000,
                    r/100*1000000, file=m)
        l=0
        d=0
        r=0

f.close()
m.close()
