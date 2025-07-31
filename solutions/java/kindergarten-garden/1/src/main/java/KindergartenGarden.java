import java.util.List;
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;

class KindergartenGarden {
    
    private final static String STUDENTS[] = {
        "Alice",
        "Bob",
        "Charlie",
        "David",
        "Eve",
        "Fred",
        "Ginny",
        "Harriet",
        "Ileana",
        "Joseph",
        "Kincaid",
        "Larry"
    };

    private Map studentPlants;
    
    KindergartenGarden(String garden) {
        this.studentPlants = new HashMap<String, List<Plant>>();
        String rows[] = garden.split("\n");
        char row0[] = rows[0].toCharArray();
        char row1[] = rows[1].toCharArray();
        
        for (int i = 0; i < STUDENTS.length && i * 2 < row0.length; i++) {
            int idxInRow = i * 2;
            List<Plant> plants = new ArrayList<Plant>();
            plants.add(Plant.getPlant(row0[idxInRow]));
            plants.add(Plant.getPlant(row0[idxInRow + 1]));
            plants.add(Plant.getPlant(row1[idxInRow]));
            plants.add(Plant.getPlant(row1[idxInRow + 1]));

            this.studentPlants.put(STUDENTS[i], plants);
        }
    }

    List<Plant> getPlantsOfStudent(String student) {
        return (List<Plant>) this.studentPlants.get(student);
    }
}