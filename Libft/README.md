# Libft

C標準ライブラリの関数を再実装する課題。
`libc` の主要関数や連結リスト操作関数などを自作し、静的ライブラリ `libft.a` としてまとめる。
以降の課題で共通の土台として利用する。

## ビルド

```sh
make        # libft.a を生成
make clean  # オブジェクトファイル(objs/)を削除
make fclean # objs/ と libft.a を削除
make re     # fclean 後に再ビルド
```

コンパイルフラグは `-Wall -Wextra -Werror`。

## 使い方

ヘッダをインクルードし、`libft.a` をリンクする。

```c
#include "libft.h"
```

```sh
cc main.c -L. -lft -I includes
```

## 構成

ソースは機能ごとにディレクトリを分けて配置している。
ヘッダは `includes/` にまとめ、`libft.h` から全体をまとめてインクルードできる。

| ディレクトリ | ヘッダ | 内容 |
| --- | --- | --- |
| `ctype/` | `ft_ctype.h` | 文字種の判定・変換 |
| `string/` | `ft_string.h` | 文字列・メモリ操作 |
| `strings/` | `ft_strings.h` | `ft_bzero` |
| `stdlib/` | `ft_stdlib.h` | 数値変換・メモリ確保 |
| `stdio/` | `ft_stdio.h` | ファイルディスクリプタへの出力 / get_next_line |
| `list/` | `ft_list.h` | 連結リスト操作 |

## 関数一覧

### ctype — 文字種の判定・変換

libc の `<ctype.h>` 相当。判定関数は条件を満たせば 0 以外、満たさなければ 0 を返す。

| 関数 | 説明 |
| --- | --- |
| `int ft_isalpha(int c)` | `c` が英字かどうかを判定する |
| `int ft_isdigit(int c)` | `c` が数字(`0`〜`9`)かどうかを判定する |
| `int ft_isalnum(int c)` | `c` が英数字かどうかを判定する |
| `int ft_isascii(int c)` | `c` がASCII文字(0〜127)かどうかを判定する |
| `int ft_isprint(int c)` | `c` が表示可能文字かどうかを判定する |
| `int ft_toupper(int c)` | 英小文字を大文字に変換する（それ以外はそのまま） |
| `int ft_tolower(int c)` | 英大文字を小文字に変換する（それ以外はそのまま） |

### string / strings — 文字列・メモリ操作

libc の `<string.h>` / `<strings.h>` 相当と、Part 2 の追加関数。

| 関数 | 説明 |
| --- | --- |
| `size_t ft_strlen(const char *s)` | 文字列 `s` の長さを返す |
| `char *ft_strchr(const char *s, int c)` | `s` の中で最初に現れる `c` の位置を返す |
| `char *ft_strrchr(const char *s, int c)` | `s` の中で最後に現れる `c` の位置を返す |
| `char *ft_strnstr(const char *haystack, const char *needle, size_t len)` | `haystack` の先頭 `len` バイト内から部分文字列 `needle` を探す |
| `int ft_strcmp(const char *s1, const char *s2)` | 2つの文字列を比較する |
| `int ft_strncmp(const char *s1, const char *s2, size_t n)` | 先頭 `n` バイトまで2つの文字列を比較する |
| `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)` | サイズ制限付きで文字列をコピーする |
| `size_t ft_strlcat(char *dst, const char *src, size_t dstsize)` | サイズ制限付きで文字列を連結する |
| `char *ft_strdup(const char *s1)` | `s1` を複製した新しい文字列を確保して返す |
| `char *ft_substr(char const *s, unsigned int start, size_t len)` | `s` の `start` から最大 `len` 文字の部分文字列を確保して返す |
| `char *ft_strjoin(char const *s1, char const *s2)` | `s1` と `s2` を連結した新しい文字列を確保して返す |
| `char *ft_strtrim(char const *s1, char const *set)` | `s1` の先頭・末尾から `set` に含まれる文字を除いた文字列を返す |
| `char **ft_split(char const *s, char c)` | `s` を区切り文字 `c` で分割し、NULL終端の文字列配列を返す |
| `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | 各文字にインデックスと文字を渡して `f` を適用した新しい文字列を返す |
| `void ft_striteri(char *s, void (*f)(unsigned int, char *))` | 各文字にインデックスとアドレスを渡して `f` を適用する（`s` を直接変更） |
| `void *ft_memset(void *b, int c, size_t len)` | メモリ領域 `b` の先頭 `len` バイトを `c` で埋める |
| `void ft_bzero(void *s, size_t n)` | メモリ領域 `s` の先頭 `n` バイトを 0 で埋める |
| `void *ft_memcpy(void *dst, const void *src, size_t n)` | `src` から `dst` へ `n` バイトコピーする |
| `void *ft_memmove(void *dst, const void *src, size_t len)` | 領域が重なっても安全に `n` バイトコピーする |
| `void *ft_memchr(const void *s, int c, size_t n)` | 先頭 `n` バイトから最初に現れる `c` の位置を返す |
| `int ft_memcmp(const void *s1, const void *s2, size_t n)` | 2つのメモリ領域を `n` バイト比較する |

### stdlib — 変換・メモリ確保

libc の `<stdlib.h>` 相当。

| 関数 | 説明 |
| --- | --- |
| `int ft_atoi(const char *str)` | 文字列を `int` に変換する |
| `long ft_strtol(const char *str)` | 文字列を `long` に変換する |
| `char *ft_itoa(int n)` | `int` を表す文字列を確保して返す（負数も対応） |
| `void *ft_calloc(size_t count, size_t size)` | `count * size` バイトを確保し 0 で初期化する |

### stdio — 出力 / get_next_line

ファイルディスクリプタへの出力と行読み込み。

| 関数 | 説明 |
| --- | --- |
| `void ft_putchar_fd(char c, int fd)` | 文字 `c` を `fd` に出力する |
| `void ft_putstr_fd(char *s, int fd)` | 文字列 `s` を `fd` に出力する |
| `void ft_putendl_fd(char *s, int fd)` | 文字列 `s` を改行付きで `fd` に出力する |
| `void ft_putnbr_fd(int n, int fd)` | 整数 `n` を `fd` に出力する |
| `char *get_next_line(int fd)` | `fd` から改行までの1行を読み込んで返す |

### list — 連結リスト操作

Part 3。`t_list` 構造体を使った連結リスト操作。

| 関数 | 説明 |
| --- | --- |
| `t_list *ft_lstnew(void *content)` | `content` を持つ新しいノードを確保して返す |
| `void ft_lstadd_front(t_list **lst, t_list *new)` | リストの先頭にノードを追加する |
| `void ft_lstadd_back(t_list **lst, t_list *new)` | リストの末尾にノードを追加する |
| `int ft_lstsize(t_list *lst)` | リストのノード数を返す |
| `t_list *ft_lstlast(t_list *lst)` | リストの最後のノードを返す |
| `void ft_lstdelone(t_list *lst, void (*del)(void *))` | `del` で content を解放し、ノード1つを解放する |
| `void ft_lstclear(t_list **lst, void (*del)(void *))` | リスト全体を `del` で解放し、ポインタを NULL にする |
| `void ft_lstiter(t_list *lst, void (*f)(void *))` | 各ノードの content に `f` を適用する |
| `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | 各 content に `f` を適用した新しいリストを生成する |

連結リストは以下の構造体で表現する。

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```
