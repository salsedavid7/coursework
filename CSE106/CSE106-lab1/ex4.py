class Courses:
        course_data = []
        def parse_file(self, name_of_file):
                file_object = open(name_of_file, "r")
                data = file_object.readlines()
                numCourses = int(data[0])
                x = 1
                for i in range(numCourses):
                        course_list = {} 
                        course_list["course_number"] = (i + 1)
                        course_list["department"] = data[x].strip()
                        x += 1
                        course_list["number"] = data[x].strip()
                        x += 1
                        course_list["name"] = data[x].strip()
                        x += 1
                        course_list["credits"] = data[x].strip()
                        x += 1
                        course_list["lecture_days"] = data[x].strip()
                        x += 1
                        course_list["start_time"] = data[x].strip()
                        x += 1
                        course_list["end_time"] = data[x].strip()
                        x += 1
                        course_list["avg_grade"] = data[x].strip()
                        x += 1
                        self.course_data.append(course_list)
        def format_data(self, output_file_name):
                file_object = open(output_file_name, "w")
                output_string = ""
                for data in self.course_data:
                        output_string += f"COURSE {data['course_number']}: {data['department']}{data['number']}: {data['name']}\n"
                        output_string += f"Number of Credits: {data['credits']}\n"
                        output_string += f"Days of Lectures: {data['lecture_days']}\n"
                        output_string += f"Lecture Time: {data['start_time']} - {data['end_time']}\n"
                        output_string += f"Stat: on average, students get {data['avg_grade']}% in this course\n\n"
                file_object.write(output_string)
class_obj = Courses()
class_obj.parse_file("classesinput.txt")
class_obj.format_data("output_file.txt")