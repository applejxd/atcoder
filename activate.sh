#!/bin/bash

if ! type "conda" >/dev/null 2>&1; then
  echo "conda is not exist."
  exit 1
fi

if ! grep -q "atcoder" <(conda env list); then
  conda env create --file environments.yml
fi

if [[ ! -e /usr/bin/chromedriver ]]; then
  sudo apt-get install -y chromium-chromedriver
fi

conda activate atcoder
oj login https://atcoder.jp/

# cf. https://qiita.com/iwaiktos/items/33ab69a42c3a1cc35dfb#3init-4010-error-utilconnecttointeropserver300-connect-failed-2
for i in $(pstree -np -s $$ | grep -o -E '[0-9]+'); do
  if [[ -e "/run/WSL/${i}_interop" ]]; then
    export WSL_INTEROP=/run/WSL/${i}_interop
  fi
done

# cf. https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md
function ojt() {
  url=$1
  name=$2

  oj download "$url"
  fname=$(echo "$name" | awk -F/ '{print $NF}' | awk -F. '{print $1}')
  g++ -std=gnu++17 -Wall -Wextra -O2 "$name" -o "$fname"
  shift 2
  oj test -N -c ./"$fname" "$@"

  rm -f "$fname"
  rm -rf test
}
