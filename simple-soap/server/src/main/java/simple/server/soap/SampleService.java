package simple.server.soap;

import javax.jws.WebMethod;
import javax.jws.WebService;
import simple.model.*;

@WebService
public interface SampleService {
	@WebMethod int getSongAmount ();

	@WebMethod Song getSongById (int songId);

	@WebMethod Storage getSongStorage ();
}
