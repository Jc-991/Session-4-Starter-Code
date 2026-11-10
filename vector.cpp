#include <iostream>
#include <string>
#include <vector>

std::vector<int> Remove_dups(const std::vector<int>& numbers){
    std::vector<int> new_numbers {};
    for(auto it = numbers.rbegin(); it != numbers.rend(); it ++){
        new_numbers.push_back(*it);
    }
    std::cout << "Reverse: ";

    for(auto num: new_numbers){
        std::cout << num << " ";
    }
    std::cout << "\n";
    return new_numbers;
}

void bubble_sort(std::vector<int>& numbers){
    for(int i = 0; i < numbers.size(); i ++){
        for(int j = i + 1; j < numbers.size(); j ++){
            int temp {0};
            if(numbers[i] > numbers[j]){
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    std::cout << "New sorted vector: ";
    for(auto num: numbers){
        std::cout << num << " ";
    }
    std::cout << "\n";
}

std::vector<std::vector<double>> Partice_selection(const std::vector<double>& energies, const std::vector<double>& radii){
    std::vector<std::vector<double>> new_events {};
    for(int i = 0; i < energies.size();  ++i){
        if(energies[i] > 3 && radii[i] < 17.0){
            std::vector<double> sub_mat {};
            sub_mat.push_back(energies[i]);
            sub_mat.push_back(radii[i]);
            new_events.push_back(sub_mat);
        }
    }
    return new_events;
}


int main(){
    std::vector<int> numbers{12, 45, 7, 89, 23, 56, 3};
    Remove_dups(numbers);
    bubble_sort(numbers);

    std::vector<double> energies{2.5, 4.2, 6.8, 3.5, 1.8, 8.1};
    std::vector<double> radii{12.0, 15.5, 17.5, 10.2, 16.0, 14.8};      
    
    std::vector<std::vector<double>> new_events = Partice_selection(energies, radii);

    std::cout << "Selected events: " << std::endl;
    for(std::vector <double> event: new_events){
        for(double i: event){
            std::cout << i << " ";
        }
        std::cout << " ";
    }
    std::cout << "\n";

    std::cout << "Selected frac: " << static_cast<double>(new_events.size()) / energies.size() * 100 << " % " << std::endl;



}