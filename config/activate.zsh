#!/bin/zsh

# サイトログイン
oj login https://atcoder.jp/

# if [[ -f /proc/sys/fs/binfmt_misc/WSLInterop ]]; then
#   # WSL でブラウザを開く際のバグフィックス
#   # cf. https://qiita.com/iwaiktos/items/33ab69a42c3a1cc35dfb#3init-4010-error-utilconnecttointeropserver300-connect-failed-2
#   for i in $(pstree -np -s $$ | grep -o -E '[0-9]+'); do
#     if [[ -e "/run/WSL/${i}_interop" ]]; then
#       export WSL_INTEROP=/run/WSL/${i}_interop
#     fi
#   done
# fi

# コンパイル・チェック自動化. 追加引数使用可能.
# ojt -> oj s で提出可能
# cf. https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md
function ojt() {
  url=$1
  name=$2

  oj download "$url"
  fname=$(echo "$name" | awk -F/ '{print $NF}' | awk -F. '{print $1}')
  g++ -std=gnu++17 -Wall -Wextra -O2 "$name" -o "$fname"
  shift 2
  oj test -c ./"$fname" "$@"

  rm -f "$fname"
  rm -rf test
}

function runcpp() {
  fname=$(echo "$1" | awk -F/ '{print $NF}' | awk -F. '{print $1}')
  g++ -std=gnu++17 -Wall -Wextra -O2 "$1" -o "$fname"
  shift
  ./"$fname" "$@"
}
alias -s {c,cc,cpp}='runcpp'

# cd completion
# cf. http://bit.ly/2ZtPPrN
setopt auto_cd
cdpath=(.. ~)
function chpwd() {
  if type "lsd" >/dev/null 2>&1; then
    lsd
  else
    ls
  fi
}
