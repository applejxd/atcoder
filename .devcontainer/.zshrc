#!/bin/zsh

#----#
# oj #
#----#

# サイトログイン
oj login https://atcoder.jp/

alias ojd="oj download"
alias ojp=oj-prepare
alias ojtest="oj test -c"
alias ojtemp="oj-template"

function ojg() {
  local naive="./naive.cpp"
  local generate="./generate.cpp"
  # cf. https://linux.just4fun.biz/?%E9%80%86%E5%BC%95%E3%81%8D%E3%82%B7%E3%82%A7%E3%83%AB%E3%82%B9%E3%82%AF%E3%83%AA%E3%83%97%E3%83%88/getopts%E3%82%92%E5%88%A9%E7%94%A8%E3%81%97%E3%81%A6%E5%BC%95%E6%95%B0%E3%82%92%E5%8F%96%E5%BE%97%E3%81%99%E3%82%8B%28bash%E3%83%93%E3%83%AB%E3%83%89%E3%82%A4%E3%83%B3%29
  while getopts "n:g:" opts; do
    case "$opts" in
      n) naive="${OPTARG}" ;;
      g) generate="${OPTARG}" ;;
      ?) echo "invalid options" >&2 ;;
    esac
  done
  [[ ! -e "$naive" ]] && return 1
  [[ ! -e "$generate" ]] && return 1
  
  naive=$(echo "$naive" | awk -F/ '{print $NF}' | awk -F. '{print $1}')
  generate=$(echo "$generate" | awk -F/ '{print $NF}' | awk -F. '{print $1}')

  g++ -std=gnu++17 -Wall -Wextra -O2 ./"$naive".cpp -o ./"$naive"
  g++ -std=gnu++17 -Wall -Wextra -O2 ./"$generate".cpp -o ./"$generate"

  # テストケース生成
  oj g/i ./"$generate" -j$(nproc) --tle 5 -f %s.%e
  # ナイーブ手法で回答生成. 計算時間が長い場合はスキップ.
  oj g/o -c ./"$naive" -j$(nproc) --tle 5
}

# コンパイル・チェック自動化. 追加引数使用可能.
# ojt -> oj s で提出可能
# cf. https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md
function ojt() {
  local name=$1
  [[ ! -e "$name" ]] && return 1

  local fname=$(echo "$name" | awk -F/ '{print $NF}' | awk -F. '{print $1}')
  g++ -std=gnu++17 -Wall -Wextra -O2 "$name" -o ./"$fname"
  shift 1
  oj test -c ./"$fname" -j$(nproc) "$@"
  rm ./"$fname"
}

function ojc() {
  [[ -e ./main ]] && rm ./main
  [[ -e ./naive ]] && rm ./naive
  [[ -e ./generate ]] && rm ./generate

  [[ -e ./test ]] && rm -rf ./test
}

function ojtt() {
  local name=$1
  [[ ! -e "$name" ]] && return 1

  local fname=$(echo "$name" | awk -F/ '{print $NF}' | awk -F. '{print $1}')
  g++ -std=gnu++17 -Wall -Wextra -O2 "$name" -o ./"$fname"
  shift 1

  local total=0
  local failed=0
  for f in ./test/*.in ; do 
    total=$(($total+1))
    if [[ -e ${f/.in/.out} ]] && ! diff <(./"$fname" < $f) ${f/.in/.out} &>/dev/null; then
      failed=$(($failed+1))
      echo "[failed]: $f"
    fi
  done
  echo "[Result]: $failed failed/$total cases"
  rm ./"$fname"
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

#---------#
# Compile #
#---------#

function runcpp() {
    fname=$(echo "$1" | awk -F/ '{print $NF}' | awk -F. '{print $1}')
    g++ -std=gnu++17 -Wall -Wextra -O2 "$1" -o "$fname"
    shift
    gdb ./"$fname" < "$@"
}
alias -s {c,cc,cpp}='runcpp'
