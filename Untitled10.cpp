#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

//  Optimal
int optimal(vector<int> pages, int frames) {
    vector<int> memory(frames, -1);
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        if (find(memory.begin(), memory.end(), pages[i]) == memory.end()) {
            pageFaults++;
            if (find(memory.begin(), memory.end(), -1) != memory.end()) {
                memory[find(memory.begin(), memory.end(), -1) - memory.begin()] = pages[i];
            } else {
                int farthest = -1, replaceIndex = -1;
                for (int j = 0; j < frames; j++) {
                    int k;
                    for (k = i + 1; k < pages.size(); k++) {
                        if (memory[j] == pages[k]) break;
                    }
                    if (k > farthest) {
                        farthest = k;
                        replaceIndex = j;
                    }
                }
                memory[replaceIndex] = pages[i];
            }
        }
    }
    return pageFaults;
}

//  LRU
int lru(vector<int> pages, int frames) {
    vector<int> memory(frames, -1);
    unordered_map<int, int> lastUsed;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        if (find(memory.begin(), memory.end(), pages[i]) == memory.end()) {
            pageFaults++;
            if (find(memory.begin(), memory.end(), -1) != memory.end()) {
                memory[find(memory.begin(), memory.end(), -1) - memory.begin()] = pages[i];
            } else {
                int lruIndex = -1, minLastUsed = i;
                for (int j = 0; j < frames; j++) {
                    if (lastUsed[memory[j]] < minLastUsed) {
                        minLastUsed = lastUsed[memory[j]];
                        lruIndex = j;
                    }
                }
                memory[lruIndex] = pages[i];
            }
        }
        lastUsed[pages[i]] = i;
    }
    return pageFaults;
}

//  FIFO
int fifo(vector<int> pages, int frames) {
    vector<int> memory(frames, -1);
    queue<int> fifoQueue;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        if (find(memory.begin(), memory.end(), pages[i]) == memory.end()) {
            pageFaults++;
            if (find(memory.begin(), memory.end(), -1) != memory.end()) {
                memory[find(memory.begin(), memory.end(), -1) - memory.begin()] = pages[i];
            } else {
                int front = fifoQueue.front();
                fifoQueue.pop();
                memory[find(memory.begin(), memory.end(), front) - memory.begin()] = pages[i];
            }
            fifoQueue.push(pages[i]);
        }
    }
    return pageFaults;
}

//  Clock
int clockPolicy(vector<int> pages, int frames) {
    vector<int> memory(frames, -1);
    vector<bool> referenceBit(frames, false);
    int pointer = 0, pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        bool pageFound = false;
        for (int j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                referenceBit[j] = true;
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            pageFaults++;
            while (referenceBit[pointer]) {
                referenceBit[pointer] = false;
                pointer = (pointer + 1) % frames;
            }
            memory[pointer] = pages[i];
            referenceBit[pointer] = true;
            pointer = (pointer + 1) % frames;
        }
    }
    return pageFaults;
}

int main() {
    int n, frames;
    cout << "Enter the number of pages: ";
    cin >> n;
    vector<int> pages(n);
    cout << "Enter the page sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    cout << "Enter the number of frames: ";
    cin >> frames;
    cout << "Optimal Page Faults: " << optimal(pages, frames) << endl;
    cout << "LRU Page Faults: " << lru(pages, frames) << endl;
    cout << "FIFO Page Faults: " << fifo(pages, frames) << endl;
    cout << "Clock Policy Page Faults: " << clockPolicy(pages, frames) << endl;

    return 0;
}