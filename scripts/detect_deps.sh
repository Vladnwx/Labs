#!/bin/bash
# Анализирует #include в файле и предлагает флаги для компиляции
grep -E '#include' "$1" | while read -r line; do
    if [[ $line == *"<SFML"* ]]; then
        echo "-lsfml-graphics -lsfml-window -lsfml-system"
    elif [[ $line == *"<GL"* ]]; then
        echo "-lglfw -lGL -lGLEW"
    fi
done | sort -u