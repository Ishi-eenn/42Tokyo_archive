# get_next_line

ファイルディスクリプタから1行ずつ読み込む関数を実装する課題。
`read()` でファイルを一定サイズ（`BUFFER_SIZE`）ずつ読み進めながら、改行までの1行を返す `get_next_line()` を自作する。

**取り組み期間:** 2023.6.3 - 2023.6.10

## 使い方

ヘッダをインクルードし、ソースを一緒にコンパイルする。
`BUFFER_SIZE`（1回の `read` で読むバイト数）はコンパイル時に `-D` で指定でき、未指定なら `4096`。

```c
#include "get_next_line.h"

char *line;
while ((line = get_next_line(fd)) != NULL)
{
	// line には改行込みの1行が入る（EOFの最終行は改行なし）
	free(line);
}
```

```sh
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

## ファイル構成

| ファイル | 内容 |
| --- | --- |
| `get_next_line.h` | プロトタイプと `BUFFER_SIZE` の定義 |
| `get_next_line.c` | `get_next_line()` 本体 |
| `get_next_line_utils.c` | 補助関数（文字列操作） |
| `get_next_line_bonus.{c,h}` | ボーナス版（複数FDの同時読み込みに対応） |
| `get_next_line_utils_bonus.c` | ボーナス版の補助関数 |

> 必須版も `fd` をインデックスとした `static` 配列でバッファを保持しており、複数のFDを並行して扱える実装になっている。

## 関数一覧

### 本体

| 関数 | 説明 |
| --- | --- |
| `char *get_next_line(int fd)` | `fd` から改行までの1行を読み込んで返す。行末の `\n` は含む。EOFに達し読むものが無い場合や、エラー時は `NULL` を返す |

### 補助関数（`get_next_line_utils.c`）

libft から必要な関数のみを持ち込んだもの。

| 関数 | 説明 |
| --- | --- |
| `size_t ft_strlen(const char *s)` | 文字列 `s` の長さを返す |
| `char *ft_strchr(const char *s, int c)` | `s` の中で最初に現れる `c`（終端 `\0` を含む）の位置を返す |
| `char *ft_strdup(const char *s1)` | `s1` を複製した新しい文字列を確保して返す |
| `char *ft_strjoin(char const *s1, char const *s2)` | `s1` と `s2` を連結した新しい文字列を確保して返す |
| `char *ft_substr(char const *s, unsigned int start, size_t len)` | `s` の `start` から最大 `len` 文字の部分文字列を確保して返す |

## 実装の流れ

`fd` ごとに読み残しを `static` 変数（`save`）へ保持しておき、呼び出しをまたいで持ち越す。

1. **read_file** — `save` に読み残しを引き継ぎつつ、`\n` を見つけるかEOFに達するまで `BUFFER_SIZE` ずつ `read` し、`ft_strjoin` で連結する。
2. **ft_clear** — 連結後の文字列を最初の `\n` の直後で切り、1行分だけを返す。残り（次の行以降）は `ft_substr` で切り出して `save` に保存する。
3. 次回呼び出し時はこの `save` から続きを処理する。

## メモリ管理

- 返り値の行は `malloc` されているため、呼び出し側で `free` する必要がある。
- 内部で確保するバッファや中間文字列はすべて解放している。
