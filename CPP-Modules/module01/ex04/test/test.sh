#!/bin/bash

# 引数の数をチェック
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 file_name old_string new_string"
    exit 1
fi

# 変数に引数を割り当て
file_name="$1"
old_string="$2"
new_string="$3"

# replace コマンドを実行してファイルの置換を行う
./replace "$file_name" "$old_string" "$new_string" &&
  # sed コマンドを使用して置換後のファイルと置換前のファイルを比較し、差分を表示
  diff_result=$(sed "s/$old_string/$new_string/g" "$file_name" | diff - "$file_name.replace")

# diff コマンドの結果に応じてメッセージを表示
if [ $? -eq 0 ]; then
  echo "$(tput setaf 2)Success$(tput sgr0)"
else
  echo "$(tput setaf 1)Failed$(tput sgr0)"
fi

# 置換後のファイルを作成
sed "s/$old_string/$new_string/g" "$file_name" > "$file_name.replace.ans"

# 置換後のファイルを削除
# rm "$file_name.replace"
