#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int optimal(vector<int> pages, int frames) {
    vector<int> memory(frames, -1); // حافظه‌ی اصلی با قاب‌های خالی
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        bool found = false;
        for (int j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            pageFaults++;
            int replaceIndex = -1, farthest = i + 1;
            for (int j = 0; j < frames; j++) {
                int k;
                for (k = i + 1; k < pages.size(); k++) {
                    if (memory[j] == pages[k]) break;
                }
                if (k == pages.size()) {
                    replaceIndex = j;
                    break;
                } else if (k > farthest) {
                    farthest = k;
                    replaceIndex = j;
                }
            }
            memory[replaceIndex] = pages[i];
        }
    }
    return pageFaults;
}

int lru(vector<int> pages, int frames) {
    vector<int> memory(frames, -1); // حافظه‌ی اصلی با قاب‌های خالی
    unordered_map<int, int> lastUsed;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        bool found = false;
        for (int j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            pageFaults++;
            int lruIndex = 0, minLastUsed = i;
            for (int j = 0; j < frames; j++) {
                if (lastUsed[memory[j]] < minLastUsed) {
                    minLastUsed = lastUsed[memory[j]];
                    lruIndex = j;
                }
            }
            memory[lruIndex] = pages[i];
        }
        lastUsed[pages[i]] = i;
    }
    return pageFaults;
}

int fifo(vector<int> pages, int frames) {
    vector<int> memory(frames, -1); // حافظه‌ی اصلی با قاب‌های خالی
    queue<int> fifoQueue;
    int pageFaults = 0, index = 0;

    for (int i = 0; i < pages.size(); i++) {
        bool found = false;
        for (int j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            pageFaults++;
            if (fifoQueue.size() < frames) {
                fifoQueue.push(index);
            } else {
                int oldest = fifoQueue.front();
                fifoQueue.pop();
                fifoQueue.push(index);
                memory[oldest] = -1;
            }
            memory[fifoQueue.back()] = pages[i];
            index = (index + 1) % frames;
        }
    }
    return pageFaults;
}

int clockPolicy(vector<int> pages, int frames) {
    vector<int> memory(frames, -1); // حافظه‌ی اصلی با قاب‌های خالی
    vector<bool> referenceBit(frames, false);
    int pointer = 0, pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        bool found = false;
        for (int j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                referenceBit[j] = true;
                found = true;
                break;
            }
        }

        if (!found) {
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