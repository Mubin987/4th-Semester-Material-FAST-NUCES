num=(0,0,0,0,0)

maximum () {
max=${num[0]}
for i in {1..4}
do
if [ ${num[$i]} -gt $max ]
then
max=${num[$i]}
fi
done
echo "The maximum value is $max"
}

minimum () {
min=${num[0]}
for i in {1..4}
do
if [ ${num[i]} -lt $min ]
then
min=${num[i]}
fi
done
echo "The minimum value is $min"
}


for i in {0..4}
do
read -p "Enter the value $((i+1)) : " num[i]
done

maximum
minimum

