// TODO: Restart, Close, Sound
#include <iostream>
#include <SDL2/SDL.h>
#include <random>
void drawState(const std::vector<int>& v, SDL_Renderer* renderer, int red, int green) {
	int index = 0;
	for (int ele : v) {
		if (index == red)
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		else if (index == green)
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		else
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLine(renderer, index, 99, index, ele);
		index++;
	}
}

void helper(const std::vector<int>& v, SDL_Renderer* renderer, int i, int j) {
	// Clear the screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Drawing the state
	drawState(v, renderer, i, j);

	// Display
	SDL_RenderPresent(renderer);
	SDL_Delay(20);
}

void bubbleSort(std::vector<int>& v, SDL_Renderer* renderer) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[j] < v[i]) {
				std::swap(v[j], v[i]);
			}
			helper(v, renderer, i, j);
		}
	}
}

void InsertionSort(std::vector<int>& A, SDL_Renderer* renderer) {
	int key, j = 0;
	for (int i = 1; i < 100; i++) { // i<=n-1=4
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;
		helper(A, renderer, i, j);
	}
}

void SelectionSort(std::vector<int>& v, SDL_Renderer* renderer) {
	for (int i = 0; i < 100; i++) {
		int min = i;
		for (int j = i + 1; j < 100; j++) {
			if (v[j] < v[min]) {
				min = j;
			}
		}
		if (min != i) {
			std::swap(v[min], v[i]);
		}
		helper(v, renderer, i, min);
	}
}
int main(int argc, char** argv) {
	std::random_device rd;
	std::uniform_int_distribution<int> d(1, 99);
	std::vector<int> v;
	for (int i = 0; i < 100; i++) {
		v.push_back(d(rd));
	}

	// GUI
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_CreateWindowAndRenderer(100 * 5, 100 * 5, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "Al-Vis");
	SDL_RenderSetScale(renderer, 5, 5);

	// Bubble Sort
	bubbleSort(v, renderer);
	// Insertion Sort
	// InsertionSort(v, renderer);
	// Selection Sort
	// SelectionSort(v, renderer);

	return 0;
}