# **Problem Filozofów i Implementacja w C++**

## **1. Opis projektu**
Projekt implementuje klasyczne zagadnienie *"Problemu pięciu filozofów"*, które ilustruje synchronizację współbieżnych procesów przy ograniczonych zasobach (widocznych jako widelce). Każdy filozof może albo myśleć, albo jeść, ale aby zjeść, musi zdobyć dwa widelce – jeden po lewej i jeden po prawej stronie.

Synchronizacja dostępu do zasobów (widelców) jest realizowana przez kelnera (*Waiter*), który zarządza dostępnością widelców i zapewnia, że żaden filozof nie zostanie zablokowany na stałe (zakleszczenie).

---

## **2. Instrukcja uruchomienia**
### **Wymagania**
- Kompilator zgodny z C++11 lub nowszym (np. `g++`).
- System operacyjny obsługujący wątki (`std::thread`).
- Terminal lub konsola do uruchamiania programu.

### **Kompilacja i uruchomienie**
```bash1
g++ -std=c++11 -o philosophers main.cpp Philosopher.cpp Waiter.cpp -lpthread

./philosophers
```
Po uruchomieniu użytkownik zostanie poproszony o podanie liczby filozofów. Następnie program zasymuluje ich życie, wyświetlając informacje o myśleniu, jedzeniu oraz zwalnianiu widelców.

### **3. Opis problemu**
Problem filozofów to przykład problemu synchronizacji wątków. Głównym wyzwaniem jest unikanie:

- Zakleszczenia (deadlock) – sytuacji, w której każdy filozof trzyma jeden widelec i czeka na drugi.
- Zagłodzenia (starvation) – gdy niektórzy filozofowie nigdy nie dostaną szansy na jedzenie.
- Warunków wyścigu (race conditions) – problemów wynikających z niekontrolowanego dostępu do współdzielonych zasobów.

Rozwiązanie w tym projekcie wykorzystuje mutex i condition_variable do kontrolowania dostępu do widelców.

### **4. Struktura programu**
### Wątki

1. **Filozofowie (Philosopher)**:
   Każdy filozof działa w oddzielnym wątku, symulując cykle myślenia i jedzenia. Filozofowie naprzemiennie myślą i jedzą, przy czym do jedzenia potrzebują dwóch widelców. Wątki filozofów współzawodniczą o dostęp do zasobów, co wymaga synchronizacji.

2. **Kelner (Waiter)**:
   Pojedynczy wątek zarządzający widelcami i przydzielaniem zasobów. Kelner dba o to, aby filozofowie nie próbowali jeść w tym samym czasie z tymi samymi widelcami, co mogłoby prowadzić do zakleszczenia.

### Sekcje krytyczne i ich rozwiązanie

W programie występują dwie główne sekcje krytyczne:

1. **Przydzielanie widelców**:
   Filozofowie proszą kelnera o dostęp do widelców poprzez funkcję `Waiter::requestToEat()`. Kelner używa `condition_variable`, aby czekać na dostępność widelców. W tej funkcji filozofowie muszą poczekać, aż oba widelce będą dostępne do użycia.

2. **Zwalnianie widelców**:
   Po zakończeniu jedzenia, filozofowie wywołują funkcję `Waiter::releaseForks()`, która zwalnia zasoby i powiadamia czekających filozofów o ich dostępności. Ta operacja pozwala uniknąć zakleszczenia i zapewnia sprawiedliwy dostęp do widelców.

Dzięki tym metodom program unika zakleszczenia i zapewnia sprawiedliwy dostęp do zasobów między filozofami.

## Synchronizacja

Synchronizacja zasobów odbywa się za pomocą zmiennych warunkowych (`condition_variable`), co pozwala na efektywne zarządzanie dostępem do widelców. W rezultacie filozofowie mogą efektywnie wykonywać swoje cykle myślenia i jedzenia, minimalizując ryzyko deadlocków.

### **5. Przykładowy wynik działania**

```bash2
Welcome to a program where you can solve a philosopher's problem!
First of all, you have to choose a number of philosophers:
5

Philosopher 0 is thinking.
Philosopher 1 is thinking.
...
Philosopher 2 is eating.
Philosopher 2 has finished eating and released forks.
...
```

Program działa w sposób ciągły, symulując filozofów, którzy myślą i jedzą, zgodnie z zasadami synchronizacji.

### **5. Możliwe usprawnienia**

- Ograniczenie czasu oczekiwania na widelec (timeout), aby zapobiec potencjalnemu zagłodzeniu filozofów.
- Losowe czasy myślenia i jedzenia dla bardziej realistycznej symulacji.
- Wizualizacja działania programu np. w formie diagramu lub GUI.
