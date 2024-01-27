# c-gettext-po-viewer

## Pre-requires

- gettext
  - include/gettext-po.h
  - lib/libgettextpo.so

## Usage

```bash
$ make && ./main sample/magit-section.ja.po sample.po
Hello, world!
argc = 3, argv[0] = ./main, argv[1] = sample/magit-section.ja.po
domains[0] = messages
domains[1] = (null)
header:
Project-Id-Version: PACKAGE VERSION
POT-Creation-Date: 2024-01-27 17:27+0900
PO-Revision-Date: 2024-01-27 16:20+0900
Last-Translator: Automatically generated
Language-Team: none
Language: ja
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
Plural-Forms: nplurals=1; plural=0;

msg:
  msgid:
  msgstr: Project-Id-Version: PACKAGE VERSION
POT-Creation-Date: 2024-01-27 17:27+0900
PO-Revision-Date: 2024-01-27 16:20+0900
Last-Translator: Automatically generated
Language-Team: none
Language: ja
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
Plural-Forms: nplurals=1; plural=0;

msg:
  msgid: Magit-Section Developer Manual
  msgstr:

$ cat sample.po
#. type: top
#: orig/magit-section.texi:4 orig/magit-section.texi:33
#: orig/magit-section.texi:45
#, no-wrap
msgid "Magit-Section Developer Manual"
msgstr ""
```
