package simple.client;

import javax.xml.ws.Endpoint;
import simple.model.*;

public class App
{
	public static void main (String[] args)
	{

		System.out.println ("Gateway: Starting SOAP");

		Song song = new Song ("A", "B", 1, 1);

		// serve SOAP
		// Endpoint.publish ("http://0.0.0.0:8080/sampleservice", new SampleServiceImp ());
	}
}
