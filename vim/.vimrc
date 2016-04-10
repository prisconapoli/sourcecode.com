set nocompatible              " be iMproved, required
filetype off                  " required

" highlighting
" cursorline
syntax on
set background=dark
set cursorline

" tabbing
set expandtab
set shiftwidth=4
set softtabstop=4

" folding settings
set foldmethod=indent
set foldnestmax=10
set nofoldenable
set foldlevel=1

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" let Vundle manage Vundle, required
Plugin 'gmarik/Vundle.vim'
Plugin 'altercation/vim-colors-solarized'
Plugin 'airblade/vim-gitgutter'
Plugin 'kien/ctrlp.vim'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required

colorscheme pablo
let g:solarized_termcolors=256
set tabstop=4

" c++11
"set makeprg=g++\ -Wall\ --std=c++11\ -g\ %
" c++14 
"set makeprg=g++\ -Wall\ --std=c++14\ -g\ %
" default
set makeprg=g++\ -Wall\ -g\ %
