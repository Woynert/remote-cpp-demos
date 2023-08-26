
package simple.generated.soap;

import javax.xml.bind.JAXBElement;
import javax.xml.bind.annotation.XmlElementDecl;
import javax.xml.bind.annotation.XmlRegistry;
import javax.xml.namespace.QName;


/**
 * This object contains factory methods for each 
 * Java content interface and Java element interface 
 * generated in the simple.generated.soap package. 
 * <p>An ObjectFactory allows you to programatically 
 * construct new instances of the Java representation 
 * for XML content. The Java representation of XML 
 * content can consist of schema derived interfaces 
 * and classes representing the binding of schema 
 * type definitions, element declarations and model 
 * groups.  Factory methods for each of these are 
 * provided in this class.
 * 
 */
@XmlRegistry
public class ObjectFactory {

    private final static QName _GetSongStorage_QNAME = new QName("http://soap.server.simple/", "getSongStorage");
    private final static QName _GetSongByIdResponse_QNAME = new QName("http://soap.server.simple/", "getSongByIdResponse");
    private final static QName _GetSongById_QNAME = new QName("http://soap.server.simple/", "getSongById");
    private final static QName _GetSongStorageResponse_QNAME = new QName("http://soap.server.simple/", "getSongStorageResponse");
    private final static QName _GetSongAmount_QNAME = new QName("http://soap.server.simple/", "getSongAmount");
    private final static QName _GetSongAmountResponse_QNAME = new QName("http://soap.server.simple/", "getSongAmountResponse");

    /**
     * Create a new ObjectFactory that can be used to create new instances of schema derived classes for package: simple.generated.soap
     * 
     */
    public ObjectFactory() {
    }

    /**
     * Create an instance of {@link GetSongStorage }
     * 
     */
    public GetSongStorage createGetSongStorage() {
        return new GetSongStorage();
    }

    /**
     * Create an instance of {@link GetSongByIdResponse }
     * 
     */
    public GetSongByIdResponse createGetSongByIdResponse() {
        return new GetSongByIdResponse();
    }

    /**
     * Create an instance of {@link GetSongById }
     * 
     */
    public GetSongById createGetSongById() {
        return new GetSongById();
    }

    /**
     * Create an instance of {@link GetSongStorageResponse }
     * 
     */
    public GetSongStorageResponse createGetSongStorageResponse() {
        return new GetSongStorageResponse();
    }

    /**
     * Create an instance of {@link GetSongAmount }
     * 
     */
    public GetSongAmount createGetSongAmount() {
        return new GetSongAmount();
    }

    /**
     * Create an instance of {@link GetSongAmountResponse }
     * 
     */
    public GetSongAmountResponse createGetSongAmountResponse() {
        return new GetSongAmountResponse();
    }

    /**
     * Create an instance of {@link Song }
     * 
     */
    public Song createSong() {
        return new Song();
    }

    /**
     * Create an instance of {@link Storage }
     * 
     */
    public Storage createStorage() {
        return new Storage();
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetSongStorage }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://soap.server.simple/", name = "getSongStorage")
    public JAXBElement<GetSongStorage> createGetSongStorage(GetSongStorage value) {
        return new JAXBElement<GetSongStorage>(_GetSongStorage_QNAME, GetSongStorage.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetSongByIdResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://soap.server.simple/", name = "getSongByIdResponse")
    public JAXBElement<GetSongByIdResponse> createGetSongByIdResponse(GetSongByIdResponse value) {
        return new JAXBElement<GetSongByIdResponse>(_GetSongByIdResponse_QNAME, GetSongByIdResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetSongById }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://soap.server.simple/", name = "getSongById")
    public JAXBElement<GetSongById> createGetSongById(GetSongById value) {
        return new JAXBElement<GetSongById>(_GetSongById_QNAME, GetSongById.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetSongStorageResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://soap.server.simple/", name = "getSongStorageResponse")
    public JAXBElement<GetSongStorageResponse> createGetSongStorageResponse(GetSongStorageResponse value) {
        return new JAXBElement<GetSongStorageResponse>(_GetSongStorageResponse_QNAME, GetSongStorageResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetSongAmount }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://soap.server.simple/", name = "getSongAmount")
    public JAXBElement<GetSongAmount> createGetSongAmount(GetSongAmount value) {
        return new JAXBElement<GetSongAmount>(_GetSongAmount_QNAME, GetSongAmount.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetSongAmountResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://soap.server.simple/", name = "getSongAmountResponse")
    public JAXBElement<GetSongAmountResponse> createGetSongAmountResponse(GetSongAmountResponse value) {
        return new JAXBElement<GetSongAmountResponse>(_GetSongAmountResponse_QNAME, GetSongAmountResponse.class, null, value);
    }

}
