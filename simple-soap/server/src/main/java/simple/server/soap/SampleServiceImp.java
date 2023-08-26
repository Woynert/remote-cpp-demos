package simple.server.soap;

import javax.jws.WebMethod;
import javax.jws.WebService;
import simple.model.*;

@WebService (endpointInterface = "simple.server.soap.SampleService")
public class SampleServiceImp implements SampleService
{
	private Storage storage;
	public SampleServiceImp (Storage storage) { this.storage = storage; }

	@WebMethod public int getSongAmount () { return 3; }

	@WebMethod public Song getSongById (int songId) { return new Song ("A", "B", 1, 1); }

	@WebMethod public Storage getSongStorage () { return this.storage; }
}
