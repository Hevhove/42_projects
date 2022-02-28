# PIPEX TESTING

## MANDATORY

if [[ ! -f infile ]]
then
	touch infile
	chmod 755 infile
	echo "hello world\n" > infile
	echo "a new line appears\n" >> infile
	echo "it's a critical hit!\n" >> infile
	echo "damage done: \n" >> infile
	echo "42 + 24\n" >> infile
fi

echo "------------------------"
echo "--PIPEX TEST MANDATORY--"
echo "------------------------"

echo "-----------"
echo "---TEST1---"
echo " Official test: "
echo "< infile ls -l | wc -l > outfile"
< infile ls -l | wc -l > outfile
echo "Result: "
cat outfile
> outfile
echo "----------"
echo "Our test: "
echo "./pipex infile \"ls -l\"  \"wc -l\" outfile"
./pipex infile "ls -l" "wc -l" outfile
echo "Result: "
cat outfile
> outfile
echo "-----------"
echo "---TEST2---"
echo " Official test: "
echo "< infile grep hell | wc -w > outfile"
< infile grep hell | wc -w > outfile
echo "Result: "
cat outfile
> outfile
echo "----------"
echo "Our test: "
echo "./pipex infile \"grep hell\"  \"wc -w\" outfile"
./pipex infile "grep hell" "wc -w" outfile
echo "Result: "
cat outfile
> outfile
echo "-----------"
echo "---TEST3---"
echo " Official test: "
echo "< infile grep 42 | bc > outfile"
< infile grep 42 | bc > outfile
echo "Result: "
cat outfile
> outfile
echo "----------"
echo "Our test: "
echo "./pipex infile \"grep 42\"  \"bc\" outfile"
./pipex infile "grep 42" "bc" outfile
echo "Result: "
cat outfile
> outfile
