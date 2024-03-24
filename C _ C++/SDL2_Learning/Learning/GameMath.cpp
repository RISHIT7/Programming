#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// already know :)
using namespace std;

int main()
{
    glm::vec3 vec1(1.0, 2.0, 3.0);
    glm::vec3 vec2(1.0, 2.0, 3.0);

    float dot = glm::dot(vec1, vec2);

    cout << dot << endl;
    return 0;
}