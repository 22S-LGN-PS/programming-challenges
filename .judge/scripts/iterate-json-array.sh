# bash .judge/scripts/iterate-json-array.sh
JSON='[ { "problem": 100, "code": "lucetre/chap01/100/main.cpp" }, { "problem": 10038, "code": "lucetre/chap02/10038/main.cpp" } ]'
readarray -t SUBMITS < <(jq -c '.[]' <<<$JSON)
USER=lucetre

SUBMIT_JSON=$(echo "" | jq)

for submit in "${SUBMITS[@]}"; do
  PROBLEM=$(jq '.problem' <<<"$submit")
  CODE=$(jq '.code' <<<"$submit")
  SUBMIT=$(jq -n \
    --arg user $USER \
    --arg problem $PROBLEM \
    --arg code $CODE \
    '.user = $user | .problem = $problem | .code = $code')
  SUBMIT_JSON=$(echo $SUBMIT_JSON $SUBMIT | jq -s '.[]')
done

echo $SUBMIT_JSON
echo $SUBMIT_JSON | jq -s '.'

# jq -c "{ \"include\": . }" <<<$JSON

# echo '[{"1":"1"}]' | jq '.[]'
