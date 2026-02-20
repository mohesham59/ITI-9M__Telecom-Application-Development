import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class StreamApi {
    public static void main(String[] args) {

        // ====== List of File ==========
        File file = new File("D:\\ITI_9monuth\\14 - Java\\Day 7");

        String[] fileList = file.list();
        System.out.println("=========== The List of File Day 7 ===========");
        for (String name : fileList) {
            System.out.print(name + " ");

            if (new File(file, name).isFile()) {
                System.out.println(" => File");
            } else {
                System.out.println(" => Folder");
            }
        }

        List<Countries> countryList = new ArrayList<>();
        List<Cities> cityList = new ArrayList<>();

        //-------------------------------------------------------
        //-------------------------------------------------------

        // ===== Read Countries File =====
        try (BufferedReader reader = new BufferedReader(new FileReader("D:\\ITI_9monuth\\14 - Java\\Day 7\\Countries.csv"))) {
            String line;

            while ((line = reader.readLine()) != null) {

                String[] parts = line.split(",");

                String code = parts[0].trim();
                String name = parts[1].trim();
                String continent = parts[2].trim();

                // parsing because data in cities are string
                long population = Long.parseLong(parts[3].trim());
                double surfaceArea = Double.parseDouble(parts[4].trim());
                double gnp = Double.parseDouble(parts[5].trim());
                int capitalId = Integer.parseInt(parts[6].trim());

                countryList.add(new Countries(code, name, continent, surfaceArea, population, gnp, capitalId));
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        //-------------------------------------------------------
        //-------------------------------------------------------

        // ===== Read Cities File =====
        try (BufferedReader reader = new BufferedReader(new FileReader("D:\\ITI_9monuth\\14 - Java\\Day 7\\Cities.csv"))) {
            String line;

            while ((line = reader.readLine()) != null) {

                String[] parts = line.split(",");

                int id = Integer.parseInt(parts[0].trim());
                String name = parts[1].trim();
                long population = Long.parseLong(parts[2].trim());
                String countryCode = parts[3].trim();

                cityList.add(new Cities(id, name, population, countryCode));
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("\n==================================");
        System.out.println("\nCountries Loaded: " + countryList.size());
        System.out.println("Cities Loaded: " + cityList.size());

        //-------------------------------------------------------
        //-------------------------------------------------------

        // ===== PopulationAnalyzer  =====
        PopulationAnalyzer analyzer = new PopulationAnalyzer(countryList, cityList);

        System.out.println("\n--- Highest Populated City per Country ---");
        analyzer.highestCityPerCountry();

        System.out.println("\n--- Most Populated Country per Continent ---");
        analyzer.mostPopulatedCountryPerContinent();

        System.out.println("\n--- Highest Populated Capital City ---");
        analyzer.highestPopulatedCapital();
    }
}
//-------------------------------------------------------
//-------------------------------------------------------
class Countries {
    private String code;
    private String name;
    private String continent;
    private double surfaceArea;
    private long population;
    private double gnp;
    private int capitalId;

    public Countries(String code, String name, String continent, double surfaceArea, long population, double gnp, int capitalId) {
        this.code = code;
        this.name = name;
        this.continent = continent;
        this.surfaceArea = surfaceArea;
        this.population = population;
        this.gnp = gnp;
        this.capitalId = capitalId;
    }

    public String getCode() {
        return code;
    }
    public String getName() {
        return name;
    }
    public String getContinent() {
        return continent;
    }
    public long getPopulation() {
        return population;
    }
    public int getCapitalId() {
        return capitalId;
    }
}
//-------------------------------------------------------
//-------------------------------------------------------
class Cities {
    private int id;
    private String name;
    private long population;
    private String countryCode;

    public Cities(int id, String name, long population, String countryCode) {
        this.id = id;
        this.name = name;
        this.population = population;
        this.countryCode = countryCode;
    }

    public int getId() {
        return id;
    }
    public String getName() {
        return name;
    }
    public long getPopulation() {
        return population;
    }
    public String getCountryCode() {
        return countryCode;
    }
}
//-------------------------------------------------------
//-------------------------------------------------------
class PopulationAnalyzer {
    private List<Countries> countries;
    private List<Cities> cities;

    public PopulationAnalyzer(List<Countries> countries, List<Cities> cities) {
        this.countries = countries;
        this.cities = cities;
    }

    public void highestCityPerCountry() {
        for (Countries country : countries) {
            Cities maxCity = cities.stream()
                    .filter(cityObj -> cityObj.getCountryCode().equals(country.getCode()))
                    .max(Comparator.comparingLong(cityObj -> cityObj.getPopulation()))
                    .orElse(null);

            if (maxCity != null) {
                System.out.println("Highest populated city of "
                        + country.getName() + " is " + maxCity.getName());
            }
        }
    }

    public void mostPopulatedCountryPerContinent() {
        countries.stream()
                .collect(Collectors.groupingBy(
                        CountriesObj -> CountriesObj.getContinent(),
                        Collectors.collectingAndThen(
                                Collectors.maxBy(Comparator.comparingLong(CountriesObj -> CountriesObj.getPopulation())),
                                optional -> optional.orElse(null)
                        )
                ))
                .forEach((continent, CountriesObj) -> {
                    if (CountriesObj != null) {
                        System.out.println("Most populated country in "
                                + continent + " is " + CountriesObj.getName());
                    }
                });
    }

    public void highestPopulatedCapital() {
        Cities maxCapital = countries.stream()
                .map(countryObj -> cities.stream()
                        .filter(cityObj -> cityObj.getId() == countryObj.getCapitalId())
                        .findFirst()
                        .orElse(null))

                .filter(cityObj -> cityObj != null)
                .max(Comparator.comparingLong(cityObj -> cityObj.getPopulation()))
                .orElse(null);

        if (maxCapital != null) {
            System.out.println("Highest populated capital city is " + maxCapital.getName());
        }
    }
}
