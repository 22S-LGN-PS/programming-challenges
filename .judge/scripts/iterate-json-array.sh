# bash .judge/scripts/iterate-json-array.sh
json=$(cat .judge/users/nick11967.yaml | yq e -o=json)
SUBMIT_JSON=$(echo $(jq -r -c '.submits' <<<"$json"))
readarray -t SUBMITS < <(jq -c '.[]' <<<$SUBMIT_JSON)

SUBMISSION=$(echo [] | jq '.[]')

for submit in "${SUBMITS[@]}"; do
  USER=lucetre
  PROBLEM=$(jq '.problem' <<<"$submit")
  CODE=$(jq '.code' <<<"$submit")

  echo $CODE
  echo $PROBLEM

  SUBMIT=$(jq -n \
    --arg user $USER \
    --arg problem $PROBLEM \
    --arg code "$CODE" \
    '.user = $user | .problem = $problem | .code = $code')
  SUBMISSION=$(echo $SUBMISSION $SUBMIT | jq -s '.[]')
done

echo $SUBMISSION | jq -s '.'
