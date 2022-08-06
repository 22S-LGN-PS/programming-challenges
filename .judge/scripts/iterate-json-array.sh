readarray -t SUBMITS < <(jq -c '.[]' <<<'[ { "problem": 100, "code": "lucetre/chap01/100/main.cpp" }, { "problem": 10038, "code": "lucetre/chap02/10038/main.cpp" } ]')

for submit in "${SUBMITS[@]}"; do
  PROBLEM=$(jq '.problem' <<<"$submit")
  CODE=$(jq '.code' <<<"$submit")
  echo $PROBLEM
  echo $CODE
done

readarray -t my_array < <(jq -c '.[]' .judge/scripts/input.json)

# iterate through the Bash array
for item in "${my_array[@]}"; do
  original_name=$(jq '.original_name' <<<"$item")
  changed_name=$(jq '.changed_name' <<<"$item")
  # do your stuff
  echo $original_name
done
