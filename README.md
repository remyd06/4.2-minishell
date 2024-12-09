1. erreur quote

2. handle quote
"truc" double quotes
tout les truc se tranforme en WORD sauf les tokens DOLLAR
'truc' single quotes
tout les truc se tranforme en WORD

3. erreur pipe

4. expander
Example: $HOME
str[0] = $
token[0] = DOLLAR

str[1] = HOME
token[0] = WORD

if token[i] = DOLLAR && token[i + 1] = WORD
	expand();

str[0] = truc pas imprimable (1 char)
token[0] = TOKENLESS

str[1] = /home/rdedola
token[1] = WORD

5. erreur redirections

6. handle redirections (stoquer tout le merdier)

7. handle command (stoquer tout les WORD restant)
