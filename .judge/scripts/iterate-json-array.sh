# bash .judge/scripts/iterate-json-array.sh
JSON='[ { "problem": 100, "code": "lucetre/chap01/100/main.cpp" }, { "problem": 10038, "code": "lucetre/chap02/10038/main.cpp" } ]'
readarray -t SUBMITS < <(jq -c '.[]' <<<$JSON)

for submit in "${SUBMITS[@]}"; do
  PROBLEM=$(jq '.problem' <<<"$submit")
  CODE=$(jq '.code' <<<"$submit")
  echo $PROBLEM
  echo $CODE
done

jq -c "{ \"include\": . }" <<<$JSON
