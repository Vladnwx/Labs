@echo off
:: Анализ #include в файле и вывод флагов линковки
findstr /R "#include.*<SFML" %1 > nul && echo -lsfml-graphics -lsfml-window -lsfml-system
findstr /R "#include.*<GL" %1 > nul && echo -lglfw3 -lopengl32 -lgdi32