g++-15 g__Generator.cpp -std=gnu++23 -o g__Generator
echo compiled gen

g++-15 g.cpp -std=gnu++23 -o g
echo compiled ans

g++-15 g__Good.cpp -std=gnu++23 -o g__Good
echo compiled good

for ((i=1;i<=100;i++)); do
    ./g__Generator > in_tmp
    (./g < in_tmp) > out
    (./g__Good < in_tmp) > ans
    if diff ans out;
        then 
            echo pass $i
        else
            echo failed test:
            sed -n 'p' in_tmp
            break
    fi
done
