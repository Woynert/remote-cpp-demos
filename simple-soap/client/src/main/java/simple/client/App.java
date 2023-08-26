package simple.client;

import java.net.URL;
import javax.xml.ws.Endpoint;
import simple.generated.soap.SampleService;
import simple.generated.soap.SampleServiceImpService;
import simple.model.*;
import simple.soapcast.*;

public class App
{
	public static void main (String[] args)
	{
		System.out.println ("Client: Consuming SOAP");

		// consume SOAP

		try {

			URL url = new URL ("http://localhost:8080/sampleservice?wsdl");

			SampleServiceImpService sampleService = new SampleServiceImpService (url);
			SampleService service = sampleService.getSampleServiceImpPort ();

			// print amount of songs

			System.out.println (String.format ("Amount of songs: %d", service.getSongAmount ()));

			// print song info

			Storage storage = CastStorage.cast (service.getSongStorage ());
			storage.print ();

		} catch (Exception e) {
			System.err.println (e);
		}
	}
}
