#!/bin/zsh

#----#
# oj #
#----#

# サイトログイン
oj login https://atcoder.jp/

# コンパイル・チェック自動化. 追加引数使用可能.
# ojt -> oj s で提出可能
# cf. https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md
function ojt() {
  local url=$1
  local name=${2:-./main.cpp}
  [[ -z "$url" ]] && return 1
  [[ ! -e "$name" ]] && return 1

  oj download "$url"
  local fname=$(echo "$name" | awk -F/ '{print $NF}' | awk -F. '{print $1}')
  g++ -std=gnu++17 -Wall -Wextra -O2 "$name" -o "$fname"
  if [[ -n "$2" ]]; then
    shift 2
    oj test -c ./"$fname" "$@"
  else
    oj test -c ./main
  fi
}

alias ojd="oj download"
alias ojp=oj-prepare
alias ojtest="oj test -c"
alias ojtemp="oj-template"

function ojg() {
  local naive=${1:-./naive.cpp}
  local generate=${2:-./generate.cpp}
  [[ ! -e "$naive" ]] && return 1
  [[ ! -e "$generate" ]] && return 1
  
  naive=$(echo "$naive" | awk -F/ '{print $NF}' | awk -F. '{print $1}')
  generate=$(echo "$generate" | awk -F/ '{print $NF}' | awk -F. '{print $1}')

  g++ -std=gnu++17 -Wall -Wextra -O2 ./"$naive".cpp -o ./"$naive"
  g++ -std=gnu++17 -Wall -Wextra -O2 ./"$generate".cpp -o ./"$generate"

  oj g/i ./"$generate" -j$(nproc) --tle 5
  oj g/o -c ./"$naive" -j$(nproc) --tle 5
}

function ojc() {
  [[ -e ./main ]] && rm ./main
  [[ -e ./naive ]] && rm ./naive
  [[ -e ./generate ]] && rm ./generate

  [[ -e ./test ]] && rm -rf ./test
}

#--------#
# Prompt #
#--------#

autoload -Uz vcs_info
precmd() { 
  vcs_info 
}
zstyle ':vcs_info:git:*' formats '%b '
setopt PROMPT_SUBST
PROMPT='%F{green}%*%f %F{blue}%~%f %F{red}${vcs_info_msg_0_}%f$ '
