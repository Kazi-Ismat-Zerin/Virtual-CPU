#include <iostream>
#include <vector>
#include <functional>

// Define a type for pipeline stages
using Stage = std::function<int(int)>;

// Simple Pipeline class
class Pipeline {
private:
    std::vector<Stage> stages;

public:
    // Add a stage to the pipeline
    void addStage(Stage stage) {
        stages.push_back(stage);
    }

    // Execute the pipeline
    int execute(int input) {
        int output = input;
        for (const auto& stage : stages) {
            output = stage(output);
        }
        return output;
    }
};

int main() {
    Pipeline pipeline;

    // Add stages to the pipeline
    pipeline.addStage([](int x) { return x + 1; });   // Stage 1: Increment
    pipeline.addStage([](int x) { return x * 2; });   // Stage 2: Double
    pipeline.addStage([](int x) { return x - 3; });   // Stage 3: Subtract 3

    // Execute the pipeline
    int input = 5;
    int result = pipeline.execute(input);

    std::cout << "Input: " << input << "\n";
    std::cout << "Result: " << result << "\n";

    return 0;
}
