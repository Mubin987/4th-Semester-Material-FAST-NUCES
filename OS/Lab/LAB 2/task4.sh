
function is_prime {
    if (( $1 < 2 ))
    then
        echo "False"
        return
    fi
    for (( i=2; i<$1; i++ ))
    do
        if (( $1 % i == 0 ))
        then
            echo "False"
            return
        fi
    done
    echo "True"
}

read -p "Enter a number: " number
if [ $(is_prime $number) == "True" ]
then
    echo "$number is a prime number."
else
    echo "$number is not a prime number."
fi