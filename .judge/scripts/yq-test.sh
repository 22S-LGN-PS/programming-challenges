# bash .judge/scripts/yq-test.sh
# cat .judge/scripts/input.yaml | yq e -o=json

USERS=$(find .judge/users -name '*.yaml')
echo "$USERS" |
    jq --slurp --raw-input 'split("\n")[:-1]' |
    jq "{\"filepath\": .[] }" |
    jq -sc "{ \"include\": . }" >users
cat ./users

matrixStringifiedObject=$(cat ./users)
