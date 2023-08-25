package simple.server.soap;

import simple.model.*;
import javax.jws.WebMethod;
import javax.jws.WebService;

@WebService (endpointInterface = "simple.server.soap.SampleService")
public class SampleServiceImp implements SampleService
{
	@WebMethod public int getSongAmount () { return 3; }

	@WebMethod public Song getSongById (int songId) { return new Song("A","B",1,1); }
}
