func(){
for file in *.c
do
gcc -o r $file
if [[ ./r -ne 0 ]];
then echo "This file has error"
else ./r
fi
done
}

echo "Compiling and Executing the listed c files"
ls *.c
func
