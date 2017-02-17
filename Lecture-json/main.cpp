#include <iostream>
#include <json/json.h>

using namespace std;

int main()
{
    json_object *jObj = json_object_new_object();
    int counter =45;
    json_object *jInt = json_object_new_int(counter);
    json_object_object_add(jObj, "counter", jInt);
    // curly brackets show your original


    string cities[5]={"Boston", "LA", "SD", "NY", "Vegas"};
    json_object *jArray = json_object_new_array();
    for (int i = 0; i < 5; i++){
        json_object *city =json_object_new_string(cities[i].c_str());
        json_object_array_add(jArray, city);
    }
    json_object_object_add(jObj, "cities", jArray);


    json_object *jObj2 = json_object_new_object();
    json_object *jStr = json_object_new_string("this is a test string");
    json_object_object_add(jObj2, "string", jStr);

    json_object *jInt2 = json_object_new_int(45);
    json_object_object_add(jObj2, "int example", jInt2);
    json_object_object_add(jObj, "second object", jObj2);


    // how does this apply to the next assignment
    json_object* jOp1 = json_object_new_object();
    json_object *jDelete = json_object_new_string("delete");
    json_object *jTitle = json_object_new_string("actual movie title");
    json_object_object_add(jOp1, "operation name", jDelete);
    json_object_object_add(jOp1, "parameter", jTitle);
    json_object_object_add(jObj, "1", jOp1);
    cout << json_object_to_json_string_ext(jObj, JSON_C_TO_STRING_PRETTY);

    json_object_object_add(jop1, "output", Movie[i])
    infile.open(Assignment6.txt, w)
    infile.close

}
